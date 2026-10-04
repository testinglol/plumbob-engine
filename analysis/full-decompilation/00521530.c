
void __fastcall FUN_00521530(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  
  iVar1 = *(int *)(param_1 + 0x88);
  uVar2 = *(undefined4 *)(param_1 + 0x4c);
  iVar3 = *(int *)(param_1 + 0x80);
  piVar4 = (int *)FUN_005e40a5();
  iVar5 = (**(code **)(*piVar4 + 0x68))(uVar2,*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
  *unaff_EBX = 0;
  unaff_EBX[1] = 0;
  unaff_EBX[3] = iVar1 - iVar3;
  unaff_EBX[2] = iVar5 + 3;
  return;
}

