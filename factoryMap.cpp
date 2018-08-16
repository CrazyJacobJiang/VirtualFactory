#pragma once
#include "factoryMap.h"

	void factoryMap::loadMap()
	{
		char path[] = "D:\\OpenGL lianxi\\ProjectClient\\Project1\\Path\\texture\\changfang.PNG";
		GLchar* ImagePath = path;
		factoryTexture.textureID=factoryTexture.readTexture(ImagePath);
		this->factory_ID=factoryTexture.textureID;
		this->factory_id = (void*)factory_ID; 
		this->factory_w = (float)factoryTexture.textureWidth;
		this->factory_h = (float)factoryTexture.textureHeight;


		char path2[] = "D:\\OpenGL lianxi\\ProjectClient\\Project1\\Path\\texture\\rouxingxian3.png";
		GLchar* ImagePath2 = path2;
		lineTexture.textureID=lineTexture.readTexture(ImagePath2);
		this->line_ID=lineTexture.textureID;
		this->line_id = (void*)line_ID; 
		this->line_w = (float)lineTexture.textureWidth;
		this->line_h = (float)lineTexture.textureHeight;



	}

	void factoryMap::drawMap()
	{
		ImGuiIO& myIo = ImGui::GetIO();
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::Image(factory_id, ImVec2(factory_w*0.5, factory_h*0.5), ImVec2(0,0), ImVec2(1,1), ImColor(255,255,255,255), ImColor(255,255,255,128));

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			float focus_sz = 32.0f;
			float focus_x = myIo.MousePos.x - pos.x - focus_sz * 0.5f; if (focus_x < 0.0f) focus_x = 0.0f; else if (focus_x > factory_w - focus_sz) focus_x = factory_w - focus_sz;
			float focus_y = myIo.MousePos.y - pos.y - focus_sz * 0.5f; if (focus_y < 0.0f) focus_y = 0.0f; else if (focus_y > factory_h - focus_sz) focus_y = factory_h - focus_sz;
			ImGui::Text("Min: (%.2f, %.2f)", focus_x, focus_y);
			ImGui::Text("Max: (%.2f, %.2f)", focus_x + focus_sz, focus_y + focus_sz);
			ImVec2 uv0 = ImVec2((focus_x) / factory_w, (focus_y) / factory_h);
			ImVec2 uv1 = ImVec2((focus_x + focus_sz) / factory_w, (focus_y + focus_sz) / factory_h);

			ImGui::Image(factory_id, ImVec2(256,256), ImVec2(uv0.x*2,uv0.y*2),ImVec2(uv1.x*2,uv1.y*2), ImColor(255,255,255,255), ImColor(255,255,255,128));
			ImGui::EndTooltip();
		}

	}

	void factoryMap::drawSmallMap( glm::vec3 &posVec )
	{
		ImGuiIO& myIo = ImGui::GetIO();
		ImVec2 pos = ImGui::GetCursorScreenPos();
		//	ImGui::Image(line_id, ImVec2(line_w*0.5, line_h*0.5), ImVec2(0,0), ImVec2(1,1), ImColor(255,255,255,255), ImColor(255,255,255,128));
		ImGui::Image(line_id, ImVec2(342*0.95, 167*0.89), ImVec2(0,0), ImVec2(1,1), ImColor(255,255,255,255), ImColor(255,255,255,128));

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			float focus_sz = 32.0f;
			float focus_x = myIo.MousePos.x - pos.x - focus_sz * 0.5f; if (focus_x < 0.0f) focus_x = 0.0f; else if (focus_x > line_w - focus_sz) focus_x = line_w - focus_sz;
			float focus_y = myIo.MousePos.y - pos.y - focus_sz * 0.5f; if (focus_y < 0.0f) focus_y = 0.0f; else if (focus_y > line_h - focus_sz) focus_y = line_h - focus_sz;
			ImGui::Text("Min: (%.2f, %.2f)", focus_x, focus_y);
			ImGui::Text("Max: (%.2f, %.2f)", focus_x + focus_sz, focus_y + focus_sz);
			ImVec2 uv0 = ImVec2((focus_x) / line_w, (focus_y) / line_h);
			ImVec2 uv1 = ImVec2((focus_x + focus_sz) / line_w, (focus_y + focus_sz) / line_h);

			ImGui::Image(line_id, ImVec2(256,256), ImVec2(uv0.x*2,uv0.y*2),ImVec2(uv1.x*2,uv1.y*2), ImColor(255,255,255,255), ImColor(255,255,255,128));
			ImGui::EndTooltip();
		}
		ImDrawList* sMap = ImGui::GetWindowDrawList();
		ImVec2 pointIn1[2]={ImVec2(171+posVec.x*2,684+posVec.z*2),ImVec2(167+posVec.x*2,692+posVec.z*2)};
		ImVec2 pointIn2[2]={ImVec2(167+posVec.x*2,692+posVec.z*2),ImVec2(171+posVec.x*2,688+posVec.z*2)};
		ImVec2 pointIn3[2]={ImVec2(171+posVec.x*2,688+posVec.z*2),ImVec2(175+posVec.x*2,692+posVec.z*2)};
		ImVec2 pointIn4[2]={ImVec2(175+posVec.x*2,692+posVec.z*2),ImVec2(171+posVec.x*2,684+posVec.z*2)};
		ImVec2 pointIn5[2]={ImVec2(171+posVec.x*2,688+posVec.z*2),ImVec2(171+posVec.x*2,698+posVec.z*2)};
		sMap->AddPolyline(pointIn1,2, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 2,false);
		sMap->AddPolyline(pointIn2,2, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 2,false);
		sMap->AddPolyline(pointIn3,2, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 2,false);
		sMap->AddPolyline(pointIn4,2, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 2,false);
		sMap->AddPolyline(pointIn5,2, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 2,false);

	}

