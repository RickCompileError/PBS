type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (another) => {
            if (val === another) return true;
            throw new Error("Not Equal");
        },
        notToBe: (another) => {
            if (val !== another) return true;
            throw new Error("Equal");
        }
    };
};

// Another version
function expect2(val: any) : ToBeOrNotToBe {
    const throwError: (arg: string) => boolean = (errorMsg) => {throw new Error(errorMsg)};
    return {
        toBe: (val2) => val2 === val ? true : throwError('Not Equal'),
        notToBe: (val2) => val2 !== val ? true : throwError('Equal')
    }
}