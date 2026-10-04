
undefined4 __fastcall FUN_004d0e7d(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 local_2c [16];
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_c;
  char local_5;
  
  local_1c = -1;
  local_18 = 0xffffffff;
  local_5 = '\0';
  *(undefined1 *)(param_1 + 0x11b) = 1;
  if (*(int **)(param_1 + 0x174) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x174) + 0x44))();
    local_5 = (**(code **)(**(int **)(param_1 + 0x174) + 0x3c))();
  }
  if ((*(char *)(param_1 + 0x188) != '\0') && (*(int **)(param_1 + 0x180) != (int *)0x0)) {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x180) + 0x50))
                              (local_2c,*(int *)(param_1 + 0x18c),
                               *(int *)(param_1 + 400) - *(int *)(param_1 + 0x18c));
    local_1c = *piVar3;
    iVar5 = piVar3[3];
    local_18 = piVar3[1];
    iVar4 = *(int *)(param_1 + 0x24);
    local_14 = piVar3[2];
    iVar1 = *(int *)(param_1 + 0x1c);
    local_c = (**(code **)(**(int **)(param_1 + 0x180) + 0x58))();
    iVar5 = iVar5 - local_18;
    iVar4 = (((iVar4 - iVar1) - local_14) + local_1c) / 2;
    local_1c = local_1c + iVar4;
    local_14 = local_14 + iVar4;
    local_18 = 0x14;
    if (*(int **)(param_1 + 0x184) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x184) + 0x60))(local_1c,0x14,local_14,iVar5 + 0x14);
    }
  }
  if (*(char *)(param_1 + 0x11a) == '\0') {
    *(undefined1 *)(param_1 + 0x11a) = 1;
    FUN_004d1cd6();
    *(undefined1 *)(param_1 + 0x11a) = 0;
  }
  if (((local_5 != '\0') && (*(int **)(param_1 + 0x5c) != (int *)0x0)) &&
     (*(char *)(param_1 + 0x168) != '\0')) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(int *)(param_1 + 0x154),*(int *)(param_1 + 0x154) + 0x14,param_1 + 0x158,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  if (((*(char *)(param_1 + 0x188) != '\0') && (*(int **)(param_1 + 0x180) != (int *)0x0)) &&
     (*(int *)(param_1 + 0x5c) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x180) + 0x78))
              (*(int *)(param_1 + 0x5c),local_1c,local_18,*(int *)(param_1 + 0x18c),
               *(int *)(param_1 + 400) - *(int *)(param_1 + 0x18c),0,0,0);
  }
  if (*(int *)(param_1 + 0x11a8) != 0) {
    cVar2 = FUN_004c24ab();
    if (cVar2 != '\0') {
      FUN_004c24d2();
    }
  }
  if (*(char *)(param_1 + 0x11b0) != '\0') {
    FUN_004d309b();
  }
  if (*(char *)(param_1 + 0x11b8) != '\0') {
    FUN_005dadbc(0,1);
    FUN_005dadbc(*(undefined4 *)(param_1 + 0x11b4),0);
    *(undefined1 *)(param_1 + 0x11b8) = 0;
  }
  return 1;
}

