
bool FUN_006213f0(uint param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = *param_4;
  if (8 < *(int *)(iVar1 + 0x18)) {
    uVar2 = (param_1 >> 0x10 & 0xff) - (param_2 >> 0x10 & 0xff);
    uVar5 = (int)uVar2 >> 0x1f;
    uVar3 = (param_1 >> 8 & 0xff) - (param_2 >> 8 & 0xff);
    uVar6 = (int)uVar3 >> 0x1f;
    uVar4 = (param_1 & 0xff) - (param_2 & 0xff);
    uVar7 = (int)uVar4 >> 0x1f;
    return (int)(((uVar2 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) + ((uVar4 ^ uVar7) - uVar7))
           <= param_3;
  }
  uVar2 = *(uint *)(iVar1 + 0x28 + param_1 * 4);
  uVar3 = *(uint *)(iVar1 + 0x28 + param_2 * 4);
  uVar4 = (uVar2 & 0xff) - (uVar3 & 0xff);
  uVar6 = (int)uVar4 >> 0x1f;
  uVar5 = (uVar2 >> 8 & 0xff) - (uVar3 >> 8 & 0xff);
  uVar7 = (int)uVar5 >> 0x1f;
  uVar2 = (uVar2 >> 0x10 & 0xff) - (uVar3 >> 0x10 & 0xff);
  uVar3 = (int)uVar2 >> 0x1f;
  return (int)(((uVar4 ^ uVar6) - uVar6) + ((uVar5 ^ uVar7) - uVar7) + ((uVar2 ^ uVar3) - uVar3)) <=
         param_3;
}

