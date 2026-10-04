
undefined4 FUN_009d9710(int *param_1)

{
  code *pcVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00c50370;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar1 = (code *)*param_1;
  if (pcVar1 == (code *)0x0) {
    pcVar1 = (code *)FUN_009d8dc0(DAT_00dd0b80 ^ (uint)&stack0xfffffffc);
    *param_1 = (int)pcVar1;
    if (pcVar1 == (code *)0x0) {
      ExceptionList = local_10;
      return 0;
    }
  }
  local_8 = 0;
  iVar2 = (*pcVar1)(0,"vkCreateInstance");
  param_1[1] = iVar2;
  if (iVar2 != 0) {
    local_8 = 1;
    iVar2 = (*(code *)*param_1)(0,"vkEnumerateInstanceExtensionProperties");
    param_1[2] = iVar2;
    if (iVar2 != 0) {
      local_8 = 2;
      iVar2 = (*(code *)*param_1)(0,"vkEnumerateInstanceLayerProperties");
      param_1[3] = iVar2;
      if (iVar2 != 0) {
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

