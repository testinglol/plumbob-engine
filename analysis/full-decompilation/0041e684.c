
uint * __thiscall FUN_0041e684(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint _Size;
  uint uVar3;
  
  _Size = param_2 + 4;
  uVar3 = 0;
  uVar1 = 8;
  do {
    if (_Size <= uVar1) {
      param_1 = uVar3 * 0x10 + param_1;
      if (*(int *)(param_1 + 0xc) == 0) {
        FUN_0041e6df();
      }
      puVar2 = *(uint **)(param_1 + 0xc);
      *(uint *)(param_1 + 0xc) = *puVar2;
      *puVar2 = uVar3 << 0x18 | _Size;
      goto LAB_0041e6b0;
    }
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 * 2;
  } while (uVar3 < 9);
  puVar2 = _malloc(_Size);
  *puVar2 = _Size | 0x80000000;
LAB_0041e6b0:
  return puVar2 + 1;
}

