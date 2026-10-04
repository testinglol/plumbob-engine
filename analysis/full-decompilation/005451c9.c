
undefined4 __fastcall FUN_005451c9(int param_1)

{
  char *_Str;
  int iVar1;
  char cVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  size_t local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar1 = *(int *)(param_1 + 0xe4);
      local_1c = *(int *)(iVar1 + 0x14);
      local_18 = *(undefined4 *)(iVar1 + 0x18);
      local_14 = *(int *)(iVar1 + 0x1c) / 3;
      local_10 = *(int *)(iVar1 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar1,&local_1c,param_1 + 0x1c,1);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  _Str = (char *)(param_1 + 0x148);
  local_8 = _strlen(_Str);
  local_1c = *(int *)(param_1 + 0xf0) + 1;
  local_14 = *(int *)(param_1 + 0xf8) + 1;
  local_18 = *(int *)(param_1 + 0xf4) + 1;
  local_10 = *(int *)(param_1 + 0xfc) + 1;
  local_c = (**(code **)(**(int **)(param_1 + 0x130) + 0x1c))();
  (**(code **)(**(int **)(param_1 + 0x130) + 0x20))(0);
  (**(code **)(**(int **)(param_1 + 0x130) + 0x80))
            (*(undefined4 *)(param_1 + 0x5c),&local_1c,_Str,local_8,1);
  (**(code **)(**(int **)(param_1 + 0x130) + 0x20))(local_c);
  (**(code **)(**(int **)(param_1 + 0x130) + 0x80))
            (*(undefined4 *)(param_1 + 0x5c),(int *)(param_1 + 0xf0),_Str,local_8,1);
  (**(code **)(**(int **)(param_1 + 0x134) + 0x80))
            (*(undefined4 *)(param_1 + 0x5c),param_1 + 0x110,*(undefined4 *)(param_1 + 0x13c),
             *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c),0);
  iVar1 = *(int *)(param_1 + 0x138);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(param_1 + 0x134) + 0x80))
              (*(undefined4 *)(param_1 + 0x5c),param_1 + 0x120,*(int *)(param_1 + 0x13c) + iVar1,
               (*(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c)) - iVar1,0);
  }
  return 1;
}

