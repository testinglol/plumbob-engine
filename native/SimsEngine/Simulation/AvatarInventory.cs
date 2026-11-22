namespace SimsEngine.Simulation;

public sealed class AvatarInventory
{
    private const int Capacity = 0x7fff;

    public sealed class Entry(int key1, int key2, short count)
    {
        public int Key1 { get; } = key1;
        public int Key2 { get; } = key2;
        public short Count { get; set; } = count;
    }

    private readonly List<Entry> _entries = [];

    public bool Changed { get; private set; }
    public void MarkChanged() => Changed = true;

    public IReadOnlyList<Entry> Entries => _entries;

    public bool Add(int key1, int key2, short count)
    {
        if (count == 0) return true;
        var found = Find(key1, key2);
        if (found >= 0)
        {
            var sum = _entries[found].Count + count;
            _entries[found].Count = sum < Capacity ? unchecked((short)sum) : (short)Capacity;
            return true;
        }
        if (_entries.Count >= Capacity) return false;
        _entries.Add(new Entry(key1, key2, count));
        return true;
    }

    public bool Remove(int key1, int key2, short count)
    {
        if (count == 0) return true;
        var found = Find(key1, key2);
        if (found < 0) return false;
        var entry = _entries[found];
        if (count == -1 || entry.Count <= 1)
            _entries.RemoveAt(found);
        else
            entry.Count--;
        return true;
    }

    public void RemoveAllOfType(int type) => _entries.RemoveAll(entry => entry.Key1 == type);

    public bool Adjust(int index, short count)
    {
        if (count == 0) return true;
        if (index < 0 || index >= _entries.Count) return false;
        if (count < 0)
        {
            _entries.RemoveAt(index);
            return true;
        }
        var next = _entries[index].Count - count;
        if (next <= 0) _entries.RemoveAt(index);
        else _entries[index].Count = unchecked((short)next);
        return true;
    }

    public short FindIndex(int key1, int key2, out short index)
    {
        var found = Find(key1, key2);
        index = found < 0 ? (short)-1 : (short)found;
        return found < 0 ? (short)0 : _entries[found].Count;
    }

    public short FindNext(int key1, ref short cursor, int key2)
    {
        var start = unchecked((short)(cursor + 1));
        for (var i = start; i >= 0 && i < _entries.Count; i++)
        {
            var entry = _entries[i];
            if (entry.Key1 == key1 && (key2 == 0 || entry.Key2 == key2))
            {
                cursor = unchecked((short)i);
                return entry.Count;
            }
        }
        cursor = -1;
        return 0;
    }

    public void FilterOut(int key1) => _entries.RemoveAll(entry => entry.Key1 == key1);

    private int Find(int key1, int key2)
    {
        for (var i = 0; i < _entries.Count; i++)
            if (_entries[i].Key1 == key1 && _entries[i].Key2 == key2) return i;
        return -1;
    }
}
