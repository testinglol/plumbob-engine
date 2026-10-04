
void __fastcall FUN_005ddddb(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    cVar1 = (**(code **)(iVar2 + 0x8c))(0x800);
    if (cVar1 != '\0') {
      FUN_005e7426();
      return;
    }
    FUN_005e743b();
    if (param_1[0x1a] != 0) break;
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 == 0) {
      iVar2 = FUN_005e749a(0);
      param_1[0x1a] = iVar2;
      goto LAB_005dde45;
    }
    param_1 = (int *)(**(code **)(*param_1 + 0x18))();
    iVar2 = *param_1;
  }
  iVar2 = param_1[0x1a];
LAB_005dde45:
  FUN_005db182(iVar2,param_1);
  return;
}

