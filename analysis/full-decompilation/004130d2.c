
undefined4 __thiscall FUN_004130d2(int param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    if (param_3 != '\0') {
      uVar2 = *(undefined4 *)(param_2 + 4);
      uVar3 = 1;
      FUN_005b8e25(uVar2,1);
      iVar1 = FUN_005b936f(uVar2,uVar3);
      *(int *)(param_1 + 4) = iVar1;
      if (iVar1 != 0) {
        FUN_005b903c(0x80,0x80);
        *(undefined1 *)(param_1 + 8) = 1;
      }
    }
    if (*(int *)(param_1 + 4) == 0) {
      *(undefined1 *)(param_1 + 8) = 0;
      uVar2 = *(undefined4 *)(param_2 + 4);
      uVar3 = 0;
      FUN_005b8e25(uVar2,0);
      iVar1 = FUN_005b936f(uVar2,uVar3);
      *(int *)(param_1 + 4) = iVar1;
      if (iVar1 != 0) {
        FUN_005b903c(0x80,0);
      }
      if (*(int *)(param_1 + 4) == 0) {
        return 0xffffffce;
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffd1;
  }
  return uVar2;
}

