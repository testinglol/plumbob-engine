
void __thiscall FUN_0041d9a9(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(param_2 + -4);
  uVar2 = *(uint *)(param_2 + -4) >> 0x18;
  if (uVar2 < 9) {
    param_1 = uVar2 * 0x10 + param_1;
    *puVar1 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 **)(param_1 + 0xc) = puVar1;
  }
  else {
    FUN_00634ecc(puVar1);
  }
  return;
}

