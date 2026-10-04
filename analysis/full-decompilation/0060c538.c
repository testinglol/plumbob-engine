
undefined8 FUN_0060c538(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar1 = param_2;
  if ((param_2 & 0x80000000) != 0) {
    bVar9 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar9 - param_2;
  }
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20);
  uVar7 = (uint)((ulonglong)param_3 * (ulonglong)param_2 >> 0x20);
  uVar8 = (uint)((ulonglong)param_4 * (ulonglong)param_1 >> 0x20);
  uVar2 = (uint)((ulonglong)param_4 * (ulonglong)param_1);
  uVar5 = (uint)CARRY4(uVar2,uVar6) +
          (uint)CARRY4(uVar2 + uVar6,(uint)((ulonglong)param_3 * (ulonglong)param_2));
  uVar2 = (uint)((ulonglong)param_4 * (ulonglong)param_2);
  uVar6 = uVar2 + uVar8;
  uVar3 = uVar6 + uVar7;
  uVar4 = uVar3 + uVar5;
  uVar2 = (int)((ulonglong)param_4 * (ulonglong)param_2 >> 0x20) + (uint)CARRY4(uVar2,uVar8) +
          (uint)CARRY4(uVar6,uVar7) + (uint)CARRY4(uVar3,uVar5);
  for (; 0x1f < param_5; param_5 = param_5 - 0x1f) {
    uVar4 = uVar4 >> 0x1f | uVar2 << 1;
    uVar2 = uVar2 >> 0x1f;
  }
  uVar6 = uVar4 >> (param_5 & 0x1f) | uVar2 << 0x20 - (param_5 & 0x1f);
  uVar2 = uVar2 >> (param_5 & 0x1f);
  if ((uVar1 & 0x80000000) != 0) {
    bVar9 = uVar6 != 0;
    uVar6 = -uVar6;
    uVar2 = -(uint)bVar9 - uVar2;
  }
  return CONCAT44(uVar2,uVar6);
}

