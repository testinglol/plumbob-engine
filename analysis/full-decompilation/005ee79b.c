
void __thiscall FUN_005ee79b(int param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_14 [16];
  
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  (**(code **)(*piVar1 + 0x24))();
  if ((*(char *)(param_1 + 0x170) == '\0') && (param_3 == '\0')) {
    if ((*(int *)(param_1 + 0x174) < *(int *)(param_1 + 0x17c)) &&
       (*(int *)(param_1 + 0x178) < *(int *)(param_1 + 0x180))) {
      iVar3 = param_1;
      uVar2 = FUN_004df599(local_14,param_1 + 0x1c);
      FUN_005ecd7f(uVar2,iVar3);
    }
    if ((*(int *)(param_1 + 0x184) < *(int *)(param_1 + 0x18c)) &&
       (*(int *)(param_1 + 0x188) < *(int *)(param_1 + 400))) {
      iVar3 = param_1;
      uVar2 = FUN_004df599(local_14,param_1 + 0x1c);
      FUN_005ecd7f(uVar2,iVar3);
    }
    if ((*(int *)(param_1 + 0x194) < *(int *)(param_1 + 0x19c)) &&
       (*(int *)(param_1 + 0x198) < *(int *)(param_1 + 0x1a0))) {
      uVar2 = FUN_004df599(local_14,param_1 + 0x1c);
      FUN_005ecd7f(uVar2,param_1);
    }
  }
  else {
    FUN_005ecd7f(param_2,param_1);
    if (param_3 == '\0') {
      *(undefined1 *)(param_1 + 0x170) = 0;
    }
  }
  return;
}

