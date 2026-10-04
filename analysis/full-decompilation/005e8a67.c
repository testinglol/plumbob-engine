
undefined4 __fastcall FUN_005e8a67(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0xe0) != 0) {
    if (((*(char *)(param_1 + 0xec) != '\0') && (*(int **)(param_1 + 0xe8) != (int *)0x0)) &&
       (cVar2 = (**(code **)(**(int **)(param_1 + 0xe8) + 0x20))(0x10), cVar2 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0xe8) + 0x9c))
                (*(undefined4 *)(param_1 + 0x5c),param_1 + 0x1c,*(int **)(param_1 + 0xe8) + 5,0);
      (**(code **)(**(int **)(param_1 + 0xe8) + 0x24))(0x10);
    }
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 0xec) = 0;
      return 0;
    }
    local_14 = *(undefined4 *)(param_1 + 0x1c);
    local_10 = *(undefined4 *)(param_1 + 0x20);
    local_c = *(undefined4 *)(param_1 + 0x24);
    local_8 = *(undefined4 *)(param_1 + 0x28);
    iVar1 = *(int *)(param_1 + 0xe0);
    local_24 = *(undefined4 *)(iVar1 + 0x14);
    local_20 = *(undefined4 *)(iVar1 + 0x18);
    local_1c = *(undefined4 *)(iVar1 + 0x1c);
    local_18 = *(undefined4 *)(iVar1 + 0x20);
    if (*(int *)(param_1 + 0xe8) != 0) {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(int *)(param_1 + 0xe8),&local_24,&local_14,0);
    }
    (*DAT_006f0674)(*(undefined4 *)(param_1 + 0x5c),&local_14,*(undefined4 *)(param_1 + 0x5c),
                    &local_14,*(undefined4 *)(param_1 + 0xe0),&local_24,
                    *(undefined4 *)(param_1 + 0xf0));
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  *(undefined1 *)(param_1 + 0xec) = 0;
  return 1;
}

