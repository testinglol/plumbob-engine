
undefined4 __fastcall FUN_005d2ba9(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  for (piVar2 = (int *)*param_1; piVar2 != (int *)param_1[1]; piVar2 = piVar2 + 1) {
    (**(code **)(**(int **)(*piVar2 + 4) + 0x1c))(*(int **)(*piVar2 + 4));
    piVar1 = *(int **)(*piVar2 + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(*piVar2 + 8) = 0;
    }
    (**(code **)(**(int **)(*piVar2 + 4) + 8))(*(int **)(*piVar2 + 4));
    *(undefined4 *)(*piVar2 + 4) = 0;
  }
  return 0;
}

