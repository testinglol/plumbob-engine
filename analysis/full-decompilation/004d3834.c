
void __thiscall FUN_004d3834(int param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x19c);
  if (piVar1 != (int *)0x0) {
    if (param_2 == '\0') {
      (**(code **)(*piVar1 + 0x98))();
      FUN_005ddfdc(0);
      (**(code **)(*piVar1 + 0x1a0))(s_Unknown_006c7cd4);
    }
    else {
      (**(code **)(*piVar1 + 0x94))();
      FUN_005ddfdc(1);
    }
  }
  return;
}

