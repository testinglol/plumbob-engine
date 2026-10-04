
char FUN_00622150(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  char cVar2;
  
  iVar1 = FUN_006220d0(param_1,param_2,param_3,0xffffffff,0xffffffff,param_4,param_5);
  cVar2 = iVar1 != 0;
  iVar1 = FUN_006220d0(param_1,param_2,param_3,0,0xffffffff,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,1,0xffffffff,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,0xffffffff,0,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,1,0,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,0xffffffff,1,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,0,1,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = FUN_006220d0(param_1,param_2,param_3,1,1,param_4,param_5);
  if (iVar1 != 0) {
    cVar2 = cVar2 + '\x01';
  }
  return cVar2;
}

