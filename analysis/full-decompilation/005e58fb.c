
undefined4 __fastcall FUN_005e58fb(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    iVar2 = *(int *)(param_1 + 0x110);
    if (iVar2 == 0) {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))
                (*(undefined4 *)(param_1 + 100),param_1 + 0x1c,0);
    }
    else {
      local_14 = *(undefined4 *)(iVar2 + 0x14);
      local_10 = *(undefined4 *)(iVar2 + 0x18);
      local_c = *(int *)(iVar2 + 0x1c) / 3;
      local_8 = *(int *)(iVar2 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar2,&local_14,param_1 + 0x1c,1);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  if (*(int *)(param_1 + 0x110) == 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(4);
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
                (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                 *(int *)(param_1 + 0x24) + -1,*(undefined4 *)(param_1 + 0x20),
                 *(undefined4 *)(param_1 + 0xf0),1);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
                (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                 *(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x28) + -1,
                 *(undefined4 *)(param_1 + 0xf0),1);
      iVar2 = *(int *)(param_1 + 0x24) + -1;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
                (iVar2,*(undefined4 *)(param_1 + 0x20),iVar2,*(int *)(param_1 + 0x28) + -1,
                 *(undefined4 *)(param_1 + 0xf4),1);
      iVar2 = *(int *)(param_1 + 0x28) + -1;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
                (*(undefined4 *)(param_1 + 0x1c),iVar2,*(int *)(param_1 + 0x24) + -1,iVar2,
                 *(undefined4 *)(param_1 + 0xf4),1);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(4);
    }
  }
  return 1;
}

