function createHelloWorld(): () => string {
    return () => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */