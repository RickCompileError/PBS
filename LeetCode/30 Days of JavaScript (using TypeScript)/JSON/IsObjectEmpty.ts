function isEmpty(obj: Record<string, any> | any[]): boolean {
    for (const _ in obj) return false;
    return true;
};