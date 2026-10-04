
uint FUN_005cb302(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5
                 )

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_80;
  ushort local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_38 [8];
  undefined4 local_18;
  
  if ((param_1 == (int *)0x0) || (param_5 == 0)) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    _memset(&local_80,0,0x7c);
    local_7c = local_7c | 0x1007;
    local_74 = param_2;
    local_80 = 0x7c;
    local_78 = param_3;
    iVar2 = *param_1;
    local_18 = 0x1800;
    puVar4 = local_38;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_4;
      param_4 = param_4 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar2 = (**(code **)(iVar2 + 0x18))(param_1,&local_80,param_5,0);
    uVar1 = (uint)(iVar2 == 0);
  }
  return uVar1;
}

