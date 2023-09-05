type Node<T> = {
    value: T;
    next: Node<T> | null;
};

export default class Stack<T> {
    public length: number;
    private _head: Node<T> | null;

    constructor() {
        this._head = null;
        this.length = 0;
    }

    push(item: T): void {
        const node: Node<T> = {
            value: item,
            next: null,
        };
        if (this.length === 0) {
            this._head = node;
        } else {
            node.next = this._head;
            this._head = node;
        }
        this.length++;
    }

    pop(): T | undefined {
        if (this.length === 0) {
            return;
        } else if (this.length === 1) {
            const temp = this._head!;
            this._head = this._head!.next;
            this.length = 0;
            return temp.value;
        } else {
            const temp = this._head!;
            this._head = this._head!.next;
            this.length--;
            return temp.value;
        }
    }

    peek(): T | undefined {
        return this._head?.value ?? undefined;
    }
}
