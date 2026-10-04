
void __thiscall
FUN_0048896c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined1 *)(param_1 + 0x3f) = 0;
  DAT_006e57e0 = param_2;
  DAT_006e57e4 = param_3;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  cVar1 = FUN_00484ba0(&param_2);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x40) = param_2;
    *(undefined4 *)(param_1 + 0x44) = param_3;
    puVar4 = param_5;
    puVar5 = (undefined4 *)(param_1 + 0x48);
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uVar2 = FUN_00488da4();
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    FUN_00489b92(uVar2);
    if ((*(int *)(param_1 + 0x34) != 1) && (*(int *)(param_1 + 0x34) != 3)) {
      if ((*(char *)(param_1 + 0x3c) == '\0') ||
         ((*(int *)(*(int *)(param_1 + 0x30) + 0x28) - *(int *)(*(int *)(param_1 + 0x30) + 0x24)) /
          0x3c == 0)) {
        FUN_00492c37();
      }
      else {
        FUN_0057a7f7(s_UI_bld_dragtool_mousedown_006c5f1c,0xfffffffc);
      }
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_0048830b();
      *(undefined1 *)(param_1 + 0x3c) = 0;
    }
  }
  return;
}

