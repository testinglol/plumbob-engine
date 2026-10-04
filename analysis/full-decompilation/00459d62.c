
void __thiscall FUN_00459d62(int *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  int iVar4;
  int unaff_retaddr;
  
  FUN_004258ed(param_1,param_1[0x37] + 0x84);
  FUN_00431edd(param_2);
  FUN_0045e5a9();
  (**(code **)(*(int *)param_1[0x2b7] + 0x24))(0);
  iVar2 = FUN_0043e088();
  if (((param_1[0x47] == iVar2) || (iVar2 = FUN_0043e093(), param_1[0x47] == iVar2)) ||
     (iVar2 = FUN_0043e09e(), param_1[0x47] == iVar2)) {
    FUN_00444346(param_1);
    (**(code **)(*param_1 + 0x38))(0);
    FUN_00442db0(CONCAT22(extraout_var,(short)param_1[0x3c]),1);
  }
  if (unaff_retaddr < 0x32) {
    do {
      iVar4 = 0;
      iVar2 = FUN_004652f7();
      if (iVar2 < 1) break;
      do {
        sVar1 = FUN_00465300(iVar4);
        iVar2 = FUN_00407498((int)sVar1);
        if ((iVar2 != 0) && (*(short *)(*(int *)(iVar2 + 0x118) + 0x12) == 2)) {
          uVar3 = FUN_00465300(iVar4);
          FUN_00465090(uVar3);
          iVar4 = -1;
          break;
        }
        iVar4 = iVar4 + 1;
        iVar2 = FUN_004652f7();
      } while (iVar4 < iVar2);
    } while (iVar4 == -1);
  }
  FUN_00459e8f();
  if ((int *)param_1[0x2b7] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x2b7] + 0x54))(0);
  }
  return;
}

