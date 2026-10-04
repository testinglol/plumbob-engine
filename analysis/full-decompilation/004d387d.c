
void __fastcall FUN_004d387d(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_retaddr;
  
  if (*(int **)(param_1 + 0x19c) == (int *)0x0) {
    return;
  }
  cVar2 = (**(code **)(**(int **)(param_1 + 0x19c) + 0x8c))(1);
  if (cVar2 == '\0') {
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x1a0))(unaff_retaddr);
  (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x19c) + 0xd4))();
  iVar3 = FUN_004cfe0d();
  if (iVar3 == 0) {
    cVar2 = FUN_004cff80();
    iVar1 = *(int *)(param_1 + 0x19c);
    piVar4 = (int *)(iVar1 + 0x7c);
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x11c) + 0x54) + 0x80);
    if (cVar2 == '\0') {
      iVar3 = (iVar3 - *(int *)(iVar1 + 0x88)) + 0x2f + *(int *)(iVar1 + 0x80);
      goto LAB_004d3922;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x88);
    piVar4 = (int *)(*(int *)(param_1 + 0x19c) + 0x7c);
  }
  iVar3 = (iVar3 - piVar4[3]) + -3 + piVar4[1];
LAB_004d3922:
  FUN_004cb21d((*(int *)(param_1 + 0x84) - piVar4[2]) + -3 + *piVar4,iVar3);
  return;
}

