
uint FUN_00639051(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *local_14;
  undefined *local_10;
  int local_c;
  undefined4 local_8;
  
  local_14 = (char *)FUN_006384a8("COMSPEC");
  if (param_1 == 0) {
    if (local_14 == (char *)0x0) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_00639cdd(local_14,0);
      uVar1 = (uint)(iVar2 == 0);
    }
  }
  else {
    local_10 = &DAT_00689380;
    local_c = param_1;
    local_8 = 0;
    if ((local_14 == (char *)0x0) ||
       ((uVar1 = FUN_006450f5(0,local_14,&local_14,0), uVar1 == 0xffffffff &&
        ((piVar3 = (int *)FUN_0063d796(), *piVar3 == 2 ||
         (piVar3 = (int *)FUN_0063d796(), *piVar3 == 0xd)))))) {
      local_14 = "command.com";
      if ((DAT_00703ab5 & 0x80) == 0) {
        local_14 = "cmd.exe";
      }
      uVar1 = FUN_00644f90(0,local_14,&local_14,0);
    }
  }
  return uVar1;
}

