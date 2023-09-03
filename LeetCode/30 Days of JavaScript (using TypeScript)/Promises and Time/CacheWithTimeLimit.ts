interface CCache {
    value: number;
    expiration: ReturnType<typeof setTimeout>;
}

class TimeLimitedCCache {

    cache: Map<number,CCache>;

    constructor() {
        this.cache = new Map<number,CCache>();
    }

    set(key: number, value: number, duration: number): boolean {
        let found = this.cache.has(key);
        if (found) clearTimeout(this.cache.get(key)?.expiration);
        this.cache.set(key, {value, expiration: setTimeout(() => this.cache.delete(key), duration)});
        return found;
    }

    get(key: number): number | undefined {
        return this.cache.has(key) ? this.cache.get(key)?.value : -1;
    }

	count(): number {
        return this.cache.size;
    }
}

/**
 * Your TimeLimitedCCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */