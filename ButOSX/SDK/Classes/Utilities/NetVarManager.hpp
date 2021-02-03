namespace NetVarManager {
    std::vector<RecvTable *> getTables();
    RecvTable* getTable(std::vector<RecvTable *> tables, const char *tableName);
    int getOffset(std::vector<RecvTable *> tables, const char *tableName, const char *propName);
    int getProp(std::vector<RecvTable *> tables, const char *tableName, const char *propName, RecvProp **prop = 0);
    int getProp(std::vector<RecvTable *> tables, RecvTable *recvTable, const char *propName, RecvProp **prop = 0);
    std::string dumpTable(RecvTable *table, int depth);
}
