
int FUN_005c0504(undefined4 param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_208 [512];
  int local_8;
  
  local_8 = FUN_005bfe47();
  if ((param_3 == -2) || (param_3 == -1)) {
    param_3 = FUN_005bfe47();
  }
  iVar3 = param_2;
  if (param_3 == local_8) {
    (**(code **)(*param_4 + 0xc))(param_1,param_2);
    return iVar3;
  }
  param_2 = param_2 * 6;
  if (param_2 < 0x200) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    puVar2 = operator_new(param_2);
    puVar4 = puVar2;
    if (puVar2 != (undefined1 *)0x0) goto LAB_005c0570;
  }
  puVar2 = local_208;
LAB_005c0570:
  iVar1 = local_8;
  *puVar2 = 0;
  iVar3 = FUN_005bfeb2(param_1,iVar3,param_3,puVar2,&param_2,iVar1);
  (**(code **)(*param_4 + 0xc))(puVar2,param_2);
  FUN_006321f0(puVar4);
  return iVar3;
}

