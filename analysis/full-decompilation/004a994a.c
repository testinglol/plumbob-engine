
undefined2 __thiscall FUN_004a994a(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined1 local_7c [119];
  char local_5;
  
  local_5 = '\0';
  FUN_004b4533(param_1);
  FUN_004b463f(0,0xf,0);
  FUN_004b463f(0,2,1);
  if (*(char *)(param_1 + 0x78) == '\0') {
    FUN_004b038a(*(undefined4 *)(param_1 + 0x70),local_7c);
    if (*(char *)(param_1 + 0x78) != '\0') {
      *(undefined4 *)(param_1 + 0x7c) = 0;
    }
    local_5 = '\x01';
  }
  uVar1 = *(undefined2 *)
           (DAT_006f0bd0 + ((DAT_006f0bd4 >> 1) * (int)(short)param_2 + (int)param_2._2_2_) * 2);
  if (local_5 != '\0') {
    FUN_004b048c(local_7c);
  }
  return uVar1;
}

