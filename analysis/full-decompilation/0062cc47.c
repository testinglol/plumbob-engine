
uint __thiscall FUN_0062cc47(int param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    if (param_2 == 0) {
      return uVar3;
    }
    if (*(int *)(param_1 + 8) == 0) {
      *(uint *)(param_1 + 0xc) =
           (uint)*(byte *)((*(uint *)(param_1 + 4) & 0xfff) + 0x10 + param_1) << 0x18;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) + 1;
      *(undefined4 *)(param_1 + 8) = 8;
    }
    uVar1 = *(uint *)(param_1 + 8);
    if (param_2 < uVar1) break;
    *(undefined4 *)(param_1 + 8) = 0;
    uVar3 = uVar3 << ((byte)uVar1 & 0x1f) | *(uint *)(param_1 + 0xc) >> (0x20 - (byte)uVar1 & 0x1f);
    param_2 = param_2 - uVar1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  bVar2 = (byte)param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - param_2;
  *(uint *)(param_1 + 0xc) = uVar1 << (bVar2 & 0x1f);
  return uVar3 << (bVar2 & 0x1f) | uVar1 >> (0x20 - bVar2 & 0x1f);
}

