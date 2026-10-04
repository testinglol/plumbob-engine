
void __fastcall FUN_0041e6df(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar3 = _malloc(param_1[1] + 8);
  puVar1 = puVar3 + 1;
  *puVar3 = param_1[2];
  uVar2 = *param_1;
  param_1[2] = (uint)puVar3;
  puVar4 = (uint *)((param_1[1] / uVar2 - 1) * uVar2 + (int)puVar1);
  for (puVar3 = puVar1; puVar3 < puVar4; puVar3 = (uint *)((int)puVar3 + uVar2)) {
    *puVar3 = uVar2 + (int)puVar3;
    uVar2 = *param_1;
  }
  *puVar4 = 0;
  param_1[3] = (uint)puVar1;
  return;
}

