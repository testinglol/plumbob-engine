
void __fastcall FUN_0050a2a2(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  if ((piVar1 != (int *)0x0) && (param_1[0x37] != 0)) {
    (**(code **)(*piVar1 + 0x20))(param_1[0x37]);
    FUN_004cb21d(0,((*(int *)(param_1[0x37] + 0x80) - *(int *)(param_1[0x37] + 0x88)) - piVar1[0x20]
                   ) + piVar1[0x22]);
    (**(code **)(*param_1 + 0x90))(0x10,1);
    (**(code **)(*(int *)param_1[0x37] + 0x90))(0x10,0);
    (**(code **)(*piVar1 + 0x54))(param_1[0x37],param_1);
    (**(code **)(*param_1 + 0x90))(0x10,0);
    (**(code **)(*(int *)param_1[0x37] + 0x90))(0x10,0);
  }
  return;
}

