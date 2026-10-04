
undefined4 __fastcall FUN_0057df9c(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x70))();
  if (cVar1 == '\0') {
    return 1;
  }
  if (((int *)param_1[0x74] != (int *)0x0) &&
     (cVar1 = (**(code **)(*(int *)param_1[0x74] + 0x70))(), cVar1 != '\0')) {
    (**(code **)(*param_1 + 0x84))(0x28,0,0);
    (**(code **)(*param_1 + 0x84))(0x29,0x13,0);
    (**(code **)(*param_1 + 0x84))(0x2a,100,0);
    *(undefined1 *)((int)param_1 + 0x1cf) = 1;
    (**(code **)(*param_1 + 0x84))(0x2d,1,0);
    return 1;
  }
  (**(code **)(*param_1 + 0x38))();
  return 1;
}

