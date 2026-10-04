
void __fastcall FUN_00502c2f(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  (**(code **)(*piVar2 + 0x14))(param_1[0x4f]);
  FUN_005dbf4d();
  return;
}

