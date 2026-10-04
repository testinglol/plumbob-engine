
undefined4 __thiscall FUN_005dd085(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  char local_6;
  byte local_5;
  
  local_5 = (**(code **)(*param_1 + 0xb0))();
  local_6 = '\0';
  cVar1 = (**(code **)(*param_1 + 0x8c))(0x8000);
  if (((cVar1 != '\0') && (cVar1 = (**(code **)(*param_1 + 0x8c))(8), cVar1 != '\0')) ||
     (cVar1 = (**(code **)(*param_1 + 0x8c))(0x80000), cVar1 != '\0')) {
    (*DAT_006f0674)(param_2,param_3,param_2,param_3,param_1[0x16],param_1 + 7,local_5);
    return 1;
  }
  if (param_1[0x2d] != 0) {
    (**(code **)(*param_1 + 0x168))();
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 != 0) {
      piVar3 = (int *)(**(code **)(*param_1 + 0x18))();
      (**(code **)(*piVar3 + 0x168))();
    }
    if ((uint)param_1[0x32] <= DAT_006e5490) {
      iVar2 = (**(code **)(*param_1 + 0x18))();
      if (iVar2 != 0) {
        iVar2 = param_1[0x2d];
        iVar4 = (**(code **)(*param_1 + 0x18))();
        if (iVar4 != 0) {
          FUN_005da644(iVar4,0x1b,param_1,iVar2,0);
        }
      }
      if (param_1[0x2d] < 1) {
        if (param_1[0x2d] < 0) {
          local_5 = 0;
          (**(code **)(*param_1 + 0x98))();
        }
      }
      else {
        local_5 = 0xff;
        (**(code **)(*param_1 + 0x16c))();
      }
      if ((char)param_1[0x33] == '\0') {
        local_6 = '\x01';
      }
      param_1[0x2d] = 0;
      if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x34])(1);
      }
      param_1[0x34] = 0;
    }
  }
  if ((local_5 & 0xf8) == 0xf8) {
    if (((param_2 != (int *)0x0) && (param_1[0x16] != 0)) &&
       (cVar1 = (**(code **)(*param_2 + 0x20))(0x10), cVar1 != '\0')) {
      (**(code **)(*param_2 + 0x9c))(param_1[0x16],param_1 + 7,param_3,0);
      (**(code **)(*param_2 + 0x24))(0x10);
    }
  }
  else if ((param_1[0x34] != 0) && ((local_5 & 0xf8) != 0)) {
    local_10 = 0;
    local_c = 0;
    (*DAT_006f0674)(param_2,param_3,param_1[0x34],&local_10,param_1[0x16],param_1 + 7,local_5);
  }
  if (local_6 == '\0') {
    return 1;
  }
  (**(code **)(*param_1 + 0x174))(0,0);
  return 1;
}

