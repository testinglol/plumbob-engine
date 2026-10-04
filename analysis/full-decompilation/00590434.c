
void __fastcall FUN_00590434(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x66] != (int)*(short *)(param_1[0x4e] + 0x58c)) {
    (**(code **)(*param_1 + 0x104))(param_1 + 5);
  }
  iVar1 = param_1[0x4e];
  if (((*(byte *)(*(int *)(iVar1 + 0x118) + 0xcc) & 4) == 0) &&
     ((param_1[5] == 0 || (1 < *(short *)(iVar1 + 0x60e))))) {
    iVar1 = (int)*(short *)(iVar1 + 0x58c);
    param_1[0x66] = iVar1;
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else if (iVar1 == 1) {
      uVar2 = 1;
    }
    else {
      if (iVar1 != 2) {
        return;
      }
      uVar2 = 2;
    }
    iVar1 = (**(code **)(*param_1 + 0xf4))(uVar2);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x100))(param_1 + 5,iVar1,0);
      *(undefined4 *)(param_1[5] + 0x40) = 1;
      FUN_00598687(0xfffffff6);
    }
  }
  return;
}

