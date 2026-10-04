
void __thiscall FUN_005eb0ad(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  if (puVar1 != (undefined4 *)0x0) {
    cVar2 = FUN_005da398(puVar1);
    if (cVar2 != '\0') {
      local_c = (int)(char)param_2;
      local_8 = 0;
      local_14 = 3;
      local_10 = 0x11;
      (**(code **)*puVar1)(&local_14);
    }
  }
  FUN_005dd715(param_2);
  return;
}

