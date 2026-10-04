
undefined1 FUN_005e35dc(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_5;
  
  local_5 = 0;
  puVar2 = (undefined4 *)FUN_005dd429(param_1,param_2);
  if (puVar2 != (undefined4 *)0x0) {
    FUN_005d9884(puVar2);
    cVar1 = FUN_005da398(puVar2);
    if (cVar1 == '\0') {
      local_5 = 0;
    }
    else {
      local_c = 0;
      local_18 = 5;
      local_14 = param_1;
      local_10 = param_2;
      local_5 = (**(code **)*puVar2)(&local_18);
    }
  }
  return local_5;
}

