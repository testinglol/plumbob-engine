
undefined4 FUN_00570f1d(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00407498(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xf4);
    *param_2 = *(undefined4 *)(iVar1 + 0xf8);
    param_2[1] = uVar2;
    uVar2 = *(undefined4 *)(iVar1 + 0x110);
    param_2[2] = uVar2;
    uVar2 = CONCAT31((int3)((uint)uVar2 >> 8),1);
  }
  return uVar2;
}

