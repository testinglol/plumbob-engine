using SimsEngine.Formats;

namespace SimsEngine.World;

public sealed class LotTiles
{
    private readonly LotArray?[] grids;

    private LotTiles(LotArray?[] grids) => this.grids = grids;

    public static LotTiles Read(IffFile lot)
    {
        LotArray? Grid(ushort id)
        {
            if (lot.Find(ResourceType.Parse("Arry"), id) is not { } chunk) return null;
            var array = LotArray.Read(lot, chunk);
            return array.Rows == LotWalls.Size && array.Width == LotWalls.Size && array.ElementSize == 1 ? array : null;
        }
        return new LotTiles([Grid(8), Grid(108)]);
    }

    public bool InsideLot(int x, int y) => grids[0] is not { } ground || (ground.Element(x, y)[0] & 0x20) == 0;

    public bool Buildable(int x, int y, int level) =>
        level is < 1 or > 2 || grids[level - 1] is not { } grid || (grid.Element(x, y)[0] & 1) != 0;
}
