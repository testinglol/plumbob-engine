
void FUN_00622cf0(int param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  int in_stack_0000001c;
  
  if (0 < in_stack_0000001c) {
    iVar2 = param_1 + 3;
    uVar1 = in_stack_0000001c + 1U >> 1;
    do {
      FUN_00622d70(param_2[3],iVar2,iVar2 + 4);
      FUN_00622d70(param_2[2],iVar2 + -1,iVar2 + 3);
      FUN_00622d70(param_2[1],iVar2 + -2,iVar2 + 2);
      FUN_00622d70(*param_2,param_1,iVar2 + 1);
      param_2 = param_2 + 4;
      param_1 = param_1 + 8;
      iVar2 = iVar2 + 8;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}

