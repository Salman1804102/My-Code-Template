bool dfs(int pos, int pre) {
    if(vis[pos]) return true;
    vis[pos] = 1;
    for(auto it : v[pos]) {
        if(it == pre) continue;
        if(dfs(it, pos)) return true;
    }
    return false;
}
