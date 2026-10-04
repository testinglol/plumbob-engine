
void __thiscall FUN_00558723(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_0055c216(param_2);
  if (iVar2 != 0) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
      iVar3 = *(int *)(param_1 + 0x148);
      iVar1 = *(int *)(iVar3 + 8);
      while (iVar1 != iVar3) {
        (**(code **)(**(int **)(iVar1 + 0x14) + 0x160))(0);
        FUN_0041674f();
        iVar3 = *(int *)(param_1 + 0x148);
      }
      FUN_0042b033();
      FUN_0042a9d1(0x1e);
      FUN_0042b902();
      FUN_0042b13f(10);
      uVar4 = param_2;
      if ((*(int *)(iVar2 + 0x24) != -1) &&
         (iVar3 = FUN_00425db3(*(int *)(iVar2 + 0x24)), *(int *)(iVar3 + 0x13c) != 0)) {
        iVar2 = FUN_00425db3(*(undefined4 *)(iVar2 + 0x24));
        uVar4 = *(undefined4 *)(iVar2 + 0x13c);
      }
      FUN_004f1b96(uVar4,0xffffffff);
    }
    FUN_005dac30(0x10,param_1,param_2);
  }
  return;
}

