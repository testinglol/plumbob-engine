
undefined4 __thiscall FUN_00602074(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_ESI;
  
  cVar1 = (**(code **)(*param_1 + 0x4c))(param_2);
  if (cVar1 == '\0') {
    do {
      (**(code **)(param_1[0xb] + 0xc))(1000);
      cVar1 = (**(code **)(*param_1 + 0x4c))(unaff_ESI);
    } while (cVar1 == '\0');
  }
  return 1;
}

