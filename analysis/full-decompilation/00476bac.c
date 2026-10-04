
void FUN_00476bac(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_006e54ac;
  if (DAT_006e54ac != (int *)0x0) {
    (**(code **)(*DAT_006e54ac + 0x18))();
  }
  DAT_006e54ac = param_1;
  piVar2 = DAT_006e54b0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))();
    piVar2 = DAT_006e54b0;
  }
  for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
    (**(code **)(*piVar2 + 0x30))(piVar1);
    (**(code **)(*piVar2 + 0x2c))(param_1);
  }
  return;
}

