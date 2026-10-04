
void __fastcall FUN_0041674f(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 4);
    while (iVar2 == *(int *)(iVar1 + 0xc)) {
      *param_1 = iVar1;
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = *param_1;
    }
    if (*(int *)(*param_1 + 0xc) != iVar1) {
      *param_1 = iVar1;
    }
  }
  else {
    for (; *param_1 = iVar1, *(int *)(iVar1 + 8) != 0; iVar1 = *(int *)(iVar1 + 8)) {
    }
  }
  return;
}

