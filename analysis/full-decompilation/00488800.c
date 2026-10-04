
void __thiscall
FUN_00488800(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (*(char *)(param_1 + 0x3d) != '\0') {
    DAT_006e57e0 = param_2;
    DAT_006e57e4 = param_3;
    *(undefined4 *)(param_1 + 0x40) = param_2;
    *(undefined4 *)(param_1 + 0x44) = param_3;
    puVar5 = param_5;
    puVar6 = (undefined4 *)(param_1 + 0x48);
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    cVar1 = FUN_00484ba0();
    if ((cVar1 == '\0') && (iVar4 = FUN_00488924(), iVar4 != 0)) {
      uVar2 = FUN_00488da4();
      *(undefined4 *)(param_1 + 0x34) = uVar2;
      FUN_00489b92();
      if (*(int *)(param_1 + 0x30) == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x3e) = 0;
      FUN_0048830b();
      if (*(char *)(param_1 + 100) == '\0') {
        return;
      }
      iVar4 = *(int *)(param_1 + 0x34);
      if ((iVar4 == 2) || (iVar4 == 3)) {
        uVar2 = 0;
        if (iVar4 == 2) {
          uVar2 = *(undefined4 *)(param_1 + 0x38);
        }
        cVar1 = FUN_0048955c(&param_2,uVar2);
      }
      else {
        if (iVar4 == 0) {
          uVar2 = *(undefined4 *)(param_1 + 0x38);
        }
        else {
          uVar2 = 0;
        }
        uVar3 = FUN_00492b26();
        cVar1 = FUN_00488de7(&param_2,uVar3,uVar2,1);
      }
      if (cVar1 != '\0') {
        *(undefined1 *)(param_1 + 0x3c) = 1;
        return;
      }
      FUN_0048830b();
      *(undefined1 *)(param_1 + 0x3c) = 0;
      return;
    }
    *(undefined1 *)(param_1 + 0x3e) = 0;
    FUN_0048830b();
    FUN_00492bc4();
  }
  return;
}

