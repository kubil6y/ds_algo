type Node<T> = {
    value: T;
    next: Node<T> | null;
};

export default class Queue<T> {
    public length: number;
    private _head: Node<T> | null;
    private _tail: Node<T> | null;

    constructor() {
        this._head = null;
        this._tail = null;
        this.length = 0;
    }

    enqueue(item: T): void {
        const node: Node<T> = {
            value: item,
            next: null,
        };
        if (this.length === 0) {
            this._head = node;
            this._tail = node;
            this.length = 1;
            return;
        } else {
            this._head!.next = node;
            this._head = node;
            this.length++;
        }
    }

    deque(): T | undefined { 
        if (this.length === 0) {
            return;
        } else if (this.length === 1) {
            const value = this._tail!.value;
            this._head = null;
            this._tail = null;
            this.length = 0;
            return value;
        } else {
            const value = this._tail!.value;
            this._tail = this._tail!.next
            this.length--;
            return value;
        }
    }

    peek(): T | undefined { 
        return this._tail?.value ?? undefined;
    }
}
