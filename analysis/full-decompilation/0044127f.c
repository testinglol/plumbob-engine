
void __thiscall FUN_0044127f(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)FUN_00407498((int)(short)param_2);
  if (piVar3 != (int *)0x0) {
    if (*(char *)(param_1 + 0x11) != '\0') {
      FUN_00447dcb(piVar3);
    }
    iVar1 = piVar3[0x16];
    iVar2 = piVar3[0x21];
    (**(code **)(*piVar3 + 0x50))(1);
    FUN_00440f2b(param_2,0);
    if ((short)iVar1 != 0) {
      FUN_0040766a(0xf3,(int)(short)iVar2);
    }
  }
  return;
}

