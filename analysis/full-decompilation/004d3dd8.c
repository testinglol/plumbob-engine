
void __thiscall FUN_004d3dd8(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = FUN_004d4090();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_004d4090();
    (**(code **)(*piVar3 + 0x58))(param_2);
  }
  iVar2 = *(int *)(param_1 + 0x11bc);
  if (iVar2 != 0) {
    if ((char)param_2 == '\0') {
      cVar1 = FUN_004cff80();
      iVar2 = *(int *)(param_1 + 0x11bc);
      if (cVar1 == '\0') {
        iVar4 = ((*(int *)(iVar2 + 0x80) - *(int *)(iVar2 + 0x88)) - *(int *)(param_1 + 0x80)) +
                -0x69 + *(int *)(param_1 + 0x88);
      }
      else {
        iVar4 = ((*(int *)(iVar2 + 0x80) - *(int *)(iVar2 + 0x88)) - *(int *)(param_1 + 0x80)) +
                -0x9b + *(int *)(param_1 + 0x88);
      }
      iVar2 = ((*(int *)(param_1 + 0x84) - *(int *)(iVar2 + 0x84)) - *(int *)(param_1 + 0x7c)) + -5
              + *(int *)(iVar2 + 0x7c);
    }
    else {
      iVar4 = ((*(int *)(param_1 + 0x88) - *(int *)(iVar2 + 0x84)) - *(int *)(param_1 + 0x80)) + -5
              + *(int *)(iVar2 + 0x7c);
      iVar2 = ((*(int *)(param_1 + 0x84) - *(int *)(iVar2 + 0x84)) - *(int *)(param_1 + 0x7c)) + -5
              + *(int *)(iVar2 + 0x7c);
    }
    FUN_004cb21d(iVar2,iVar4);
  }
  return;
}

