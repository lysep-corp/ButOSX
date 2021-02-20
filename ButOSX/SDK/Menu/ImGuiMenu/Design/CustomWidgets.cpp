//
//  CustomWidgets.cpp
//  ButOSX
//
//  Created by Can on 31.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "CustomWidgets.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include "xorstr.h"

bool CustomWidgets::SubTab(const char* label, const ImVec2& size_arg, const bool selected)
{
    ImGuiButtonFlags flags = 0;
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;
    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    
    
    ImVec2 pos = window->DC.CursorPos;

    ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;
    if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat) flags |= ImGuiButtonFlags_Repeat; 
    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);
    if (selected){
        window->DrawList->AddRectFilled({ bb.Min.x,bb.Min.y }, { bb.Max.x,bb.Max.y }, ImColor(0.23f, 0.23f, 0.23f, style.Alpha));
        window->DrawList->AddRectFilled(ImVec2(bb.Min.x, bb.Max.y - 4), ImVec2(bb.Max.x, bb.Max.y), ImColor(0.99f, 0.43f, 0.f, style.Alpha));
    }
    else{
        window->DrawList->AddRectFilled({ bb.Min.x,bb.Min.y }, { bb.Max.x,bb.Max.y }, ImColor(0.11f, 0.11f, 0.11f, style.Alpha));
    }
    //window->DrawList->AddText(ImVec2(((pos.x + size.x) - label_size.x) / 2, ((pos.y + size.y) - label_size.y) / 2), ImColor(255, 255, 255), label);
    //window->DrawList->AddText(ImVec2(bb.Min.x + 5, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2), ImColor(255,255,255, 255), label);
    return pressed;
}

bool CustomWidgets::Switch(const char* label, bool* v)
{

    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    float height = 20.00f;
    float width = height * 1.45f;
    ImGuiWindow* window = ImGui::GetCurrentWindow();

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    float radius = height * 0.50f;
    float radius2 = height * 0.70f;

    const float square_sz = ImGui::GetFrameHeight();
    ImVec2 pos = window->DC.CursorPos;
    const ImRect total_bb(pos, ImVec2(pos.x + square_sz + (label_size.x > 5.0f ? style.ItemInnerSpacing.x + label_size.x : 5.0f), pos.y + label_size.y + style.FramePadding.y * 3.0f)); 
    ImGui::InvisibleButton(label, ImVec2(width, height));
    if (ImGui::IsItemClicked())
        *v = !*v;
    const ImRect check_bb(ImVec2(pos.x, pos.y), ImVec2(pos.x + square_sz, pos.y + square_sz));
    float t = *v ? 1.0f : 0.0f;
    ImGui::SameLine();
    ImGui::SameLine();
    ImGui::RenderText(ImVec2(18 + check_bb.Max.x + style.ItemInnerSpacing.x, check_bb.Min.y + style.FramePadding.y - 5), label);
    float ANIM_SPEED = 0.25f;
    if (g.LastActiveId == g.CurrentWindow->GetID(label))
    {
        float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
        t = *v ? (t_anim) : (1.0f - t_anim);
    }

    ImU32 col_bg, top_bg2;
    if (ImGui::IsItemHovered()) {
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.17f, 0.21f, 0.24f, 1.00f), ImVec4(0.15f, 0.82f, 0.35f, 1.00f), t));
        top_bg2 = IM_COL32(103, 23, 244, 50);

    }
    else
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.17f, 0.21f, 0.24f, 1.00f), ImVec4(0.15f, 0.82f, 0.35f, 1.00f), t));
    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + 13.f), col_bg, height * 0.5f); // top arkası
    if (ImGui::IsItemClicked())
        draw_list->AddCircleFilled(ImVec2(p.x + radius - 2.f + t * (width + 5.f - radius * 2.0f), p.y + radius / 1.5), radius - 1.5f, ImColor(1.0f, 1.0f, 1.0f, style.Alpha), 30); //top
    else
        draw_list->AddCircleFilled(ImVec2(p.x + radius - 2.f + t * (width + 5.f - radius * 2.0f), p.y + radius / 1.5), radius - 1.5f, ImColor(1.0f, 1.0f, 1.0f, style.Alpha), 30); //top

    if (ImGui::IsItemHovered())
        draw_list->AddCircleFilled(ImVec2(p.x + radius2 - 6.f + t * (width + 13.f - radius2 * 2.0f), p.y + radius2 / 2), radius2 - 0.5f, IM_COL32(255, 255, 255, 50), 24); // saydam top

    if (window->SkipItems)
        return false;
    
    ImGui::ItemSize(total_bb, style.FramePadding.y);


    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
    if (pressed)
    {
        *v = !(*v);
        ImGui::MarkItemEdited(id);
    }

    return pressed;
}

void CustomWidgets::Spinner(float radius, float thickness, int num_segments, ImVec4 color) {
    auto window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;

    auto &g = *GImGui;
    auto &&pos = ImGui::GetCursorPos();
    ImVec2 size{radius * 2, radius * 2};
    const ImRect bb{pos, ImVec2(pos.x + size.x, pos.y + size.y)};
    ImGui::ItemSize(bb);
    if (!ImGui::ItemAdd(bb, 0))
        return;

    window->DrawList->PathClear();
    int start = static_cast<int>(abs(ImSin(static_cast<float>(g.Time * 1.8f)) * (num_segments - 5)));
    const float a_min = IM_PI * 2.0f * ((float) start) / (float) num_segments;
    const float a_max = IM_PI * 2.0f * ((float) num_segments - 3) / (float) num_segments;
    const auto &&centre = ImVec2(pos.x + radius, pos.y + radius);
    for (auto i = 0; i < num_segments; i++) {
        const float a = a_min + ((float) i / (float) num_segments) * (a_max - a_min);
        auto time = static_cast<float>(g.Time);
        window->DrawList->PathLineTo({centre.x + ImCos(a + time * 8) * radius,
                                      centre.y + ImSin(a + time * 8) * radius});
    }
    window->DrawList->PathStroke(ImGui::GetColorU32(color), false, thickness);
}

bool CustomWidgets::ControlBox(void (*UnHookFunction)(), bool* HideShowBool, bool* FullScreenBool){
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10);
    
    //Close Button
    style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.36f, 0.33f, style.Alpha);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.56f, 0.53f, style.Alpha);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.26f, 0.23f, style.Alpha);
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
    ImGui::SetCursorPos(ImVec2(10, 9));
    if (ImGui::Button(xorstr("X"), ImVec2(10, 10)))
        UnHookFunction();
    
    //Minimize Button
    style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.76f, 0.20f, style.Alpha);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.96f, 0.40f, style.Alpha);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.66f, 0.10f, style.Alpha);
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
    ImGui::SetCursorPos(ImVec2(25, 9));
    if (ImGui::Button(xorstr("_"), ImVec2(10, 10)))
        *HideShowBool = false;
    
    //Fullscreen Button
    style.Colors[ImGuiCol_Button] = ImVec4(0.14f, 0.49f, 0.20f, style.Alpha);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.14f, 0.69f, 0.40f, style.Alpha);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.14f, 0.39f, 0.10f, style.Alpha);
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
    ImGui::SetCursorPos(ImVec2(40, 9));
    if (ImGui::Button(xorstr("<>"), ImVec2(10, 10)))
        *FullScreenBool = !*FullScreenBool;
    ImGui::PopStyleVar();
    return true;
}
