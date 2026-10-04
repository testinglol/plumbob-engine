
uint __thiscall FUN_0050ab4a(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int local_8;
  
  uVar3 = param_3;
  iVar2 = param_2;
  if (((((int)param_3 < 0x32) || ((int)param_2 < 0)) ||
      (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80) <= (int)param_3)) ||
     (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c) <= (int)param_2)) {
    param_3 = param_3 & 0xffffff;
    local_8 = param_1;
    cVar4 = FUN_004cff80();
    if (((((cVar4 != '\0') && (*(int *)(param_1 + 0xd8) == 0)) &&
         ((0x207 < iVar2 && ((-1 < (int)uVar3 && ((int)uVar3 < 0x32)))))) &&
        (iVar1 = *(int *)(param_1 + 0x10c), iVar1 != 0)) && (*(int **)(iVar1 + 0x60) != (int *)0x0))
    {
      cVar4 = (**(code **)(**(int **)(iVar1 + 0x60) + 0x20))(0x40);
      if (cVar4 != '\0') {
        param_2 = (**(code **)(**(int **)(iVar1 + 0x60) + 0xcc))();
        iVar5 = (**(code **)(**(int **)(iVar1 + 0x60) + 0xd0))();
        if (0x80 < *(byte *)(iVar5 * uVar3 + param_2 + -0x231 + iVar2)) {
          param_3 = CONCAT13(1,(undefined3)param_3);
        }
        (**(code **)(**(int **)(iVar1 + 0x60) + 0x24))(0x40);
      }
    }
  }
  else {
    param_3 = CONCAT13(1,(undefined3)param_3);
    local_8 = param_2;
    param_2 = uVar3;
    if (*(int *)(param_1 + 0xdc) != 0) {
      FUN_004d26ba(*(int *)(param_1 + 0xdc),&local_8,&param_2);
      cVar4 = (**(code **)(**(int **)(param_1 + 0xdc) + 0x74))(local_8,param_2);
      if (cVar4 != '\0') {
        param_3 = 0;
      }
    }
  }
  return param_3 >> 0x18;
}

