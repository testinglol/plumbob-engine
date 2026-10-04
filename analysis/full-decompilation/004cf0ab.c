
void __thiscall FUN_004cf0ab(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x48) = param_2;
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x80;
  if (iVar1 == param_2) {
    return;
  }
  if (param_3 != 0) {
    return;
  }
  if (param_2 == 1) {
    uVar2 = 0;
LAB_004cf0e7:
    FUN_004a8361(uVar2);
    uVar2 = 0;
  }
  else {
    if (param_2 == 2) {
      uVar2 = 1;
      goto LAB_004cf0e7;
    }
    if (param_2 == 8) {
      FUN_0042004f();
      uVar2 = 1;
      goto LAB_004cf12c;
    }
    FUN_004a8361(0);
    uVar2 = 1;
  }
  FUN_004a8392(uVar2);
  uVar2 = 0;
LAB_004cf12c:
  FUN_004b1668(uVar2,0);
  return;
}

