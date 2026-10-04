
undefined4 __fastcall FUN_00511453(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar3 != '\0') {
      iVar2 = *(int *)(param_1 + 0x11c);
      if (iVar2 != 0) {
        local_14 = *(int *)(iVar2 + 0x14);
        local_10 = *(int *)(iVar2 + 0x18);
        local_c = *(int *)(iVar2 + 0x1c) / 3;
        local_8 = *(int *)(iVar2 + 0x20) / 3;
        (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar2,&local_14,param_1 + 0x1c,1);
      }
      piVar1 = (int *)(param_1 + 0x128 + *(int *)(param_1 + 0x13c) * 4);
      if (*(int *)(param_1 + 0x128 + *(int *)(param_1 + 0x13c) * 4) != 0) {
        iVar2 = *piVar1;
        iVar5 = (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) + -0xb4;
        iVar4 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -0x96;
        local_10 = *(int *)(iVar2 + 0x18) + iVar4 + *(int *)(param_1 + 0x80);
        local_14 = *(int *)(iVar2 + 0x14) + iVar5 + *(int *)(param_1 + 0x7c);
        local_c = *(int *)(iVar2 + 0x1c) + iVar5 + *(int *)(param_1 + 0x7c);
        local_8 = *(int *)(iVar2 + 0x20) + iVar4 + *(int *)(param_1 + 0x80);
        iVar2 = *piVar1;
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar2,iVar2 + 0x14,&local_14,0);
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

