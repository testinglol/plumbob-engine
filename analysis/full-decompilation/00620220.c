
void FUN_00620220(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  
  if (0 < param_2) {
    do {
      FUN_00636e50();
      uVar1 = __ftol();
      *param_1 = uVar1;
      param_1 = param_1 + 4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

